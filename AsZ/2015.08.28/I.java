import java.io.*;
import java.math.*;
import java.util.*;
import java.text.*;

public class I {

	/**
	 * @param args
	 */
	static final int MAXN = 1010;
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		
		int ca = cin.nextInt();
		
		BigInteger[] f = new BigInteger[MAXN];
		f[0] = BigInteger.ZERO;
		f[1] = BigInteger.ONE;
		final BigInteger MO = BigInteger.valueOf(258280327);
		for (int i = 2; i < MAXN; ++i)
			f[i] = f[i - 1].add(f[i - 2]);
		for (; ca > 0; --ca)
		{
			int n = cin.nextInt();
			BigInteger m = cin.nextBigInteger();
			BigInteger ans = BigInteger.ZERO;
			if (m.compareTo(f[3]) <= 0)
			{
				out.println(0);
			} else 
			{
				for (int i = n; i >= 1; --i)
					if (m.compareTo(f[i]) >= 0)
					{
						
						if (m.equals(f[i]))
						{		
							ans = f[i - 2];
						}
						else 
						{
							for (int j = i; j >= 1; --j)
								if (m.compareTo(f[j]) == 1)
								{
									m = m.subtract(f[j]);
								} else if (m.equals(f[j]))
								{
									ans = m;
									break;
								}
						}
						out.println(ans.mod(MO));
						break;
					}
			}
		}
		
		out.flush();
	}

}
