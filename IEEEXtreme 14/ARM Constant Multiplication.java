import java.io.DataInputStream;
import java.io.FileInputStream;
import java.io.IOException;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Arrays;
public class Main {
    static class Reader
    {
        final private int BUFFER_SIZE = 1 << 16;
        private DataInputStream din;
        private byte[] buffer;
        private int bufferPointer, bytesRead;
        public Reader()
        {
            din = new DataInputStream(System.in);
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
        public Reader(String file_name) throws IOException
        {
            din = new DataInputStream(new FileInputStream(file_name));
            buffer = new byte[BUFFER_SIZE];
            bufferPointer = bytesRead = 0;
        }
        public String readLine() throws IOException
        {
            byte[] buf = new byte[64]; // line length
            int cnt = 0, c;
            while ((c = read()) != -1)
            {
                if (c == '\n')
                    break;
                buf[cnt++] = (byte) c;
            }
            return new String(buf, 0, cnt);
        }
        public int nextInt() throws IOException
        {
            int ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do
            {
                ret = ret * 10 + c - '0';
            } while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
        public long nextLong() throws IOException
        {
            long ret = 0;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (neg)
                return -ret;
            return ret;
        }
        public double nextDouble() throws IOException
        {
            double ret = 0, div = 1;
            byte c = read();
            while (c <= ' ')
                c = read();
            boolean neg = (c == '-');
            if (neg)
                c = read();
            do {
                ret = ret * 10 + c - '0';
            }
            while ((c = read()) >= '0' && c <= '9');
            if (c == '.')
            {
                while ((c = read()) >= '0' && c <= '9')
                {
                    ret += (c - '0') / (div *= 10);
                }
            }
            if (neg)
                return -ret;
            return ret;
        }
        private void fillBuffer() throws IOException
        {
            bytesRead = din.read(buffer, bufferPointer = 0, BUFFER_SIZE);
            if (bytesRead == -1)
                buffer[0] = -1;
        }
        private byte read() throws IOException
        {
            if (bufferPointer == bytesRead)
                fillBuffer();
            return buffer[bufferPointer++];
        }
        public void close() throws IOException
        {
            if (din == null)
                return;
            din.close();
        }
    }
    static class Point {
        double x , y ;
        int value ;
        public Point(double x,double y , int value) {
            this.x = x ;
            this.y = y ;
            this.value = value ;
        }
    }
    public static void main(String []args ) throws IOException {
        long inst[] = new long[32] ;
        int index = 0 , power , sign = 1;
        Reader r = new Reader();
        int t = r.nextInt();
        for(int i =0 ; i<t;i++) {
            inst = new long[32];
            index =0 ;
            long c = r.nextLong();
            while(c!=0 && c!=1) {
                power = findClosetPower2(Math.abs(c));
                if(c > 0 ) sign = -1 ;
                else {
                    sign=1 ;
                }
                inst[index++] = (long)Math.pow(2,power)*(-1*sign);
                c+= (Math.pow(2,power)*sign);
            }
            if(c==1) inst[index] = 1;
            printInstructions(inst);
        }
    }
    public static void printInstructions(long []in) {
        int power = 0 ;
        for (int i = 0; i < in.length; i++) {
            if (in[i] == 0) break;
            power = (int)(Math.log(Math.abs(in[i]))/Math.log(2));
            if(in[i] > 0) {
                    printAdd(1 , 1 , 0 , (power));
            }
            else {
                    printSUB(1 , 1 , 0 , (power));
            }
        }
        printMOV(0 , 1 , 0);
        System.out.println("END");
    }
    public static void printAdd(int d , int x , int y , int shift ){
        System.out.println("ADD R"+d + ", R"+x+ ", R"+y + ", LSL #"+shift);
    }
    public static void printSUB(int d , int x , int y , int shift ){
        System.out.println("SUB R"+d + ", R"+x+ ", R"+y + ", LSL #"+shift);
    }
    public static void printMOV(int d , int x, int shift ){
        System.out.println("MOV R"+d + ", R"+x+ ", LSL #"+shift);
    }
    public static int findClosetPower2(long x) {
        double upper = Math.ceil(Math.log(x)/Math.log(2)) ;
        if(upper == 32) return 31 ;
        if(Math.pow(2,upper) - x >= x - Math.pow(2 , upper-1)) {
            return (int)upper-1 ;
        }
        return (int)upper ;
    }
}
