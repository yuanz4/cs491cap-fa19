import java.util.*;
public class Main {
 public static final int MAX = 300000;
 public static void main(String args[]) {
  Scanner input = new Scanner(System.in);
  int n = input.nextInt(), sh[] = new int[MAX];
  boolean vis[] = new boolean[MAX];
  long d[] = new long[MAX];
  for (int i = 1; i <= n; i++){
   sh[i] = input.nextInt();
  }
  Arrays.fill(d, Long.MAX_VALUE);
  d[1] = 0;
  Queue<Integer> q = new LinkedList<>();
  vis[1] = vis[0] = true;
  q.add(1);
     while(!q.isEmpty())
     {
         int t = q.poll();
         //System.out.println(q.size());
         if (d[t+1]>d[t]+1 && t+1 <=n)
         {
             d[t+1]=d[t]+1;
             if(!vis[t+1]) {
              q.add(t+1);
             }
             vis[t+1]=true;
         }
         if(d[sh[t]]>d[t]+1)
         {
             d[sh[t]]=d[t]+1;
             if(!vis[sh[t]])q.add(sh[t]);
             vis[sh[t]]=true;
         }
         if(d[t-1]>d[t]+1 && t <= n)
         {
             d[t-1]=d[t]+1;
             if(!vis[t-1])q.add(t-1);
             vis[t-1]=true;
         }
         //System.out.println(q.size());
     }
  for(int i=1;i<=n;++i) {
      System.out.print(d[i] + " ");
  }
 }
}