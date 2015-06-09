import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;

public class Main {

	/**
	 * @param args
	 */
	
	public static BigInteger calc(BigInteger x, int y)
	{
		BigInteger ans = BigInteger.ONE;
		for (int i = 1; i < y + 1; ++i)
		{
			ans = ans.multiply(x.add(BigInteger.valueOf(1 - i)));
			ans = ans.divide(BigInteger.valueOf(i));
		}
		return ans;
	}
	public static BigInteger get(int a, BigInteger b)
	{
		BigInteger l = BigInteger.valueOf(2 * a - 1);
		BigInteger r = BigInteger.valueOf(10);
		BigDecimal tt;
		tt.
		r = r.pow(50);
		for (;;)
		{
			BigInteger tmp = l.add(BigInteger.ONE);
			if (tmp.compareTo(r) >= 0)
				break;
			tmp = l.add(r);
			BigInteger mid = tmp.divide(BigInteger.valueOf(2));
			tmp = calc(mid, a);
			if (tmp.compareTo(b) < 0) l = mid;
			else r = mid;
		}
		return r;
	}
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		File srcFile = new File("discuss.in");
		File desFile = new File("discuss.out");
		try{
			Scanner cin = new Scanner(new BufferedInputStream(new FileInputStream(srcFile)));
			PrintWriter out = new PrintWriter(new BufferedOutputStream(new FileOutputStream(desFile)));
			BigInteger z, ans;
			z = cin.nextBigInteger();
			ans = z;
			for (int i = 2; i < 201; ++i)
			{
				BigInteger y = get(i, z);
				if (z.equals(calc(y, i)))
					ans = y;
			}
			out.println(ans);
			out.flush();
		}
	catch(IOException e)
		{
			
		}
	}

}
