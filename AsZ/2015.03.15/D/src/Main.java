import java.io.*;
import java.util.*;
import java.math.*;


public class Main {

	public static class cir
	{
			int x, y;
			int r;
			BigInteger p, q;
			int clk;
			int sqr(int tt)
			{
				return tt * tt;
			}
			boolean isCross(cir V)
			{
				return sqr(V.r + r) == sqr(V.x - x) + sqr(V.y - y);
			}
			cir(int x1, int y1)
			{
				x = x1; y = y1;
			}
	}
	/**
	 * @param args
	 */
	public static int num;

	

	public static final int MAXN = 2123;
	

	public static cir[] g = new cir[MAXN];
	public static int[] fir = new int[MAXN];
	public static int[] nxt = new int[MAXN * MAXN];
	public static int[] e = new int[MAXN * MAXN];
	public static int[] vis = new int[MAXN];
	
	public static void link(int u, int v)
	{
		e[++num] = v;
		nxt[num] = fir[u];
		fir[u] = num;
	}
	

	public static void dfs(int u, int fa)
	{
		vis[u] = 1;
		for (int p = fir[u]; p > 0; p = nxt[p])
			if (vis[e[p]] == 0)
			{
				int v = e[p];
				g[v].clk = 1 - g[u].clk;
				g[v].p = g[u].p.multiply(BigInteger.valueOf(g[u].r));
				g[v].q = g[u].q.multiply(BigInteger.valueOf(g[v].r));
				BigInteger tmp = g[v].p.gcd(g[v].q);
				if (tmp.compareTo(BigInteger.ZERO) != 0)
				{
					g[v].p = g[v].p.divide(tmp);
					g[v].q = g[v].q.divide(tmp);
				}
				dfs(e[p], u);
			}
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner cin = new Scanner(new BufferedInputStream(System.in));
		PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));
		int T = cin.nextInt();
		
		for (int i = 0; i < MAXN; ++i)
			g[i] = new cir(0, 0);
		for (; T > 0; --T)
		{
			int n = cin.nextInt();
			
			num = 0;
			Arrays.fill(fir, 0);
			Arrays.fill(vis, 0);
			
			for (int i = 0; i < n; ++i)
			{
				//g[i] = new cir;
				g[i].x = cin.nextInt();
				g[i].y = cin.nextInt();
				g[i].r = cin.nextInt();
				g[i].p = BigInteger.ZERO;
				g[i].q = BigInteger.ONE;
				g[i].clk = 0;
				for (int j = 0; j < i; ++j)
						if (g[i].isCross(g[j]))
						{
							link(i, j);
							link(j, i);
						}
			}
			g[0].p = BigInteger.ONE;
			g[0].q = BigInteger.ONE;
			g[0].clk = 0;
			dfs(0, 0);
		
			for (int i = 0; i < n; ++i)
			{
				if (g[i].p.equals(BigInteger.ZERO))
				{
					out.println("not moving");
				} else 
				{
					if (g[i].q.equals(BigInteger.ONE))
					{
						out.print(g[i].p);
					} else out.print(g[i].p + "/" + g[i].q);
					if (g[i].clk == 0) out.println(" " + "clockwise");
					else out.println(" counterclockwise");
				}
				out.flush();
			}
		}

	}

}
