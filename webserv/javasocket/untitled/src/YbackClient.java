import java.io.*;
import java.net.*;
import java.util.HashMap;
import java.util.Map;
import java.util.*;

public class YbackClient {

	public static void main(String[] args) {
		Socket socket = null;
		BufferedReader in = null;
		BufferedReader in2 = null;
		PrintWriter out = null;
		InetAddress ia = null;

		try {
			ia = InetAddress.getLocalHost();

			socket = new Socket(ia, 3333);
			in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
			in2 = new BufferedReader(new InputStreamReader(System.in));
			out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(socket.getOutputStream())));

			System.out.println(socket.toString());
		} catch (IOException ignored) {

		}

		try {
			System.out.print("서버로 보낼 메세지 : ");
			String data = in2.readLine();

			System.out.println("Sent Request: " + data + "\n");

			out.println(data);
			out.flush();
			socket.close();
		} catch (IOException ignored) {

		}
	}
}
