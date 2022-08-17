<<<<<<< HEAD
=======
# get_next_line

## 프로젝트 시작 전에 알아야 할 것들

- [File Descriptor](https://www.notion.so/File-Descriptor-3bce42daac3445e48dd1da86531d3037)
- [read()](https://www.notion.so/read-e130eebc84ca4bbca227875f5e62ea4a)
- [static variable](https://www.notion.so/static-variable-47cea9220ec54360a581ba0aeb05e42d)

## 프로젝트 요구 사항

프로젝트에서 요구하는 것이 정확히 무엇인지 이해하는데 시간이 오래 걸렸다. 하지만 프로젝트에서 요구하는 바를 이해한다면 해당 로직을 짜는데는 비교적 짧은 시간이 걸린다.

프로젝트의 요구 사항

- GNL 함수는 한 번 호출할 때마다 개행문자를 만나면 그 개행문자까지의 문자열을 모두 반환한다.
- 각각 독립적인 호출은 해당 텍스트 파일의 줄을 순서대로 읽어야 한다.
- file, redirection, stdin을 읽었을 때에도 함수가 제대로 동작해야 한다.
- 프로젝트에서 `-D BUFFER_SIZE=?` 플래그로 컴파일할 시에 터미널에서 `BUFFER_SIZE`의 크기를 설정해줘야 한다.
- 보너스
  - 여러 파일을 동시에 열어서 `file_descriptor`가 여러 개 선언 되었을 때에도 GNL 함수가 각각의 파일에 대한 기능을 수행하게 구현해야 한다.

## 프로젝트 로직

1. 파일을 read 할 임시 버퍼를 선언한다.

```c
char  *tmp;

tmp = malloc(BUFFER_SIZE + 1);
```

- 이 `tmp` 포인터는 `strjoin` 함수에 사용하기 때문에 마지막에 NULL 자리를 보장해줘야 한다.
  - 마지막에 NULL을 넣어주는 것을 잊지말자.

2. `read`한 임시 버퍼를 개행 문자가 있을 때까지 저장할 static 버퍼를 선언한다.

```c
static char *backup;
```

3. `read(fd, tmp, BUFFER_SIZE);` 을 반복문으로 개행 문자를 만날 때까지 돌려준다.

- 계속 read 함수를 호출하면 `fd`에 해당하는 파일을 `tmp`에 `BUFFER_SIZE`만큼 저장을 하는 것이기 때문에 반복문의 마지막에는 `backup = ft_strjoin(backup, tmp);` 를 사용하면서 tmp에 있는 데이터를 `backup`에 차곡차곡 쌓아준다.
- 만약 개행 문자를 만나지 못했다면 마지막 줄일 가능성이 있기 때문에 메모리를 할당했던 `tmp`를 `free` 시켜준다.
  - 당연하게 반복문은 개행문자를 포함하는 순간에 반복을 정지해야한다.

4. 개행문자를 포함하고 있는 static 변수 `backup`에서 개행문자까지의 문자열을 `ans` 포인터에 할당해준다.

5. `backup`에 개행문자 다음에 다른 문자열이 이어질 수 있으므로 개행문자 뒤의 문자열을 다시 `backup`에 넣어준다.

    ```c
    backup = making_newbackup(backup);
    ```

6. `ans`를 반환한다.

## Trouble Shooting

bonus part의 테스터 중에 open함수를 사용해서 `fd`를 초기화시켜주고, GNL 함수로 몇 줄을 읽어 준 후에 해당 파일의 `fd`를 `close`시켜줬다. 그리고 다시 그 파일을 `open`해서 `fd`를 다시 초기화시키고 GNL 함수로 모두 읽어준 후에 마지막에 GNL의 파라미터로 NULL을 넣어줬는데, 계속 메모리 누수가 발생했다.

read 함수가 `NULL`을 읽는다면 -1을 반환하는데, 이 때 원래 메모리가 할당되어 있던 static 변수 `backup`이 메모리가 해제되지 않은 채로 값을 반환하고 끝나기 때문에 메모리 누수가 발생한 것이었다.

고치기 전의 코드

```c
if (fd < 0 || BUFFER_SIZE <= 0)
  return (0);
```

고친 후의 코드

```c
if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, backup[fd], 0) == -1)
 {
  if (backup[fd])
   free_null(&backup[fd]);
  return (0);
 }
```

이 코드를 GNL 함수가 시작하자마자 실행되게 만들었다. read 함수가 NULL을 읽을 경우 만약 해당 fd의 backup 변수에 값이 존재한다면 malloc이 해제되지 않았다는 소리이므로 이를 free시켜주는 free_null 함수를 호출했다.

이렇게 코드를 고쳐서 어떠한 상황에도 메모리 누수가 없게끔 만들었다.
>>>>>>> 55ccf330b7b412e9ba4ce8e42a0ce2a30425b17f
