import java.util.*;
import java.io.*;
import java.math.BigInteger;

class counting {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));

		int c = Integer.parseInt(br.readLine());

		for (int i = 0; i < c; i++) {
			StringTokenizer st = new StringTokenizer(br.readLine());
			String nStr = st.nextToken(), sStr = st.nextToken();
			BigInteger n = new BigInteger(nStr), s = new BigInteger(sStr);

			BigInteger zero = new BigInteger("0"), ten = new BigInteger("10");
			// try to bring n to 0 instead
			int steps = 0;
			int x = 20;
			while (n.compareTo(zero) > 0) {
				if (s.multiply(ten.pow(x)).compareTo(n) <= 0) {
					n = n.subtract(s.multiply(ten.pow(x)));
					steps++;
				} else if (x > 0) {
					x--;
				} else {
					break;
				}
			}
			System.out.println(new BigInteger(steps + "").add(n));
		}

		br.close();
		pw.close();
	}
}

