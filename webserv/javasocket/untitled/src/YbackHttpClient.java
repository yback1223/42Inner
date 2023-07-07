import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.net.HttpURLConnection;
import java.net.URL;

public class YbackHttpClient {
	public static void main(String[] args) {
		try {
			// HTTP GET 요청을 보낼 URL 설정
			URL url = new URL("http://localhost:8080");

			// HttpURLConnection 객체 생성
			HttpURLConnection connection = (HttpURLConnection) url.openConnection();

			// 요청 메소드 설정
			connection.setRequestMethod("GET");

			// 응답 코드 확인
			int responseCode = connection.getResponseCode();
			System.out.println("Response Code: " + responseCode);

			// 응답 메시지 읽기
			BufferedReader reader = new BufferedReader(new InputStreamReader(connection.getInputStream()));
			String line;
			StringBuilder response = new StringBuilder();
			while ((line = reader.readLine()) != null) {
				response.append(line);
			}
			reader.close();

			// 응답 출력
			System.out.println("Response Body:");
			System.out.println(response.toString());

			// 연결 종료
			connection.disconnect();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
