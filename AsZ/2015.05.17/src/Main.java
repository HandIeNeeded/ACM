import java.util.*;
import java.io.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	public static BigInteger[][] f = new BigInteger[222][4];
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		try{
			File srcFile = new File("derangements.in");
			File desFile = new File("derangements.out");
			Scanner cin = new Scanner(new BufferedInputStream(new FileInputStream(srcFile)));
			PrintWriter cout = new PrintWriter(new OutputStreamWriter(new FileOutputStream(desFile)));
			int N = cin.nextInt();
			f[0][0] = BigInteger.ONE;
			f[1][0] = BigInteger.ONE;
			f[1][1] = BigInteger.ZERO;
			for (int n = 2; n <= N; ++n)
			{
				f[n][0] = f[n - 2][0].multiply(BigInteger.valueOf(4 * (n - 1)));
				BigInteger tmp = f[n - 1][1].multiply(BigInteger.valueOf(2 * (n - 1)));
				f[n][0] = f[n][0].add(tmp);
				f[n][0] = f[n][0].add(f[n - 1][0]);
				
				f[n][1] = f[n - 2][0].multiply(BigInteger.valueOf(4 * (n - 1)));
				tmp = f[n - 1][1].multiply(BigInteger.valueOf(2 * (n - 1)));
				f[n][1] = f[n][1].add(tmp);
			}
			cout.println(f[N][0]);
			cout.flush();
		}
		catch(IOException e)
		{
		}
	}

}
