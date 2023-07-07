import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class YbackServer {

	public static void main(String[] args) {

		Socket socket = null;
		ServerSocket server_socket = null;
		BufferedReader in = null;
		PrintWriter out = null;

		try {
			server_socket = new ServerSocket(3333);
		} catch (IOException e) {
			System.out.println("해당 포트가 열려있습니다.");
		}

		try {
			System.out.println("서버가 열렸습니다.");
			socket = server_socket.accept();

			in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())));

			String str = null;
			str = in.readLine();

			System.out.println("Client로부터 온 메세지 : " + str);

			out.write(str);
			out.flush();
			socket.close();
		} catch (IOException ignored) {

		}
	}
}
