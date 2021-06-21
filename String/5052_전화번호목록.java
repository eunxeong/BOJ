import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.Arrays;

public class Main {
    public static void main(String[] args) throws Exception{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

        int t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            int n = Integer.parseInt(br.readLine());
            String[] array = new String[n];
            boolean flag = true;

            for(int i = 0; i < n; i++){
                array[i] = br.readLine();
            }

            Arrays.sort(array);

            for(int i = 0; i < n - 1; i++){
                int cur = array[i].length();
                int nxt = array[i + 1].length();

                if (cur < nxt) {
                    if (array[i + 1].indexOf(array[i]) == 0){
                        flag = false;
                        break;
                    }
                }
            }

            if (flag)   bw.write("YES\n");
            else    bw.write("NO\n");

        }

        bw.flush();
        bw.close();
        br.close();
    }
}
