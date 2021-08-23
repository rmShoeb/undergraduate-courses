public class Race{
    public static int counter = 0;
    public static boolean flag[] = {false, false};
    // public static int turn;
    public static void increase(){counter++;}
    public static void decrease(){counter--;}

    public static void main(String[] args) {
        Thread t1 = new Thread(new Runnable(){
            public void run(){
                flag[0] = true;
                // turn = 1;
                for(int i=0; i<10000; i++)
                    increase();
                flag[0] = false;
            }
        });
        Thread t2 = new Thread(new Runnable(){
            public void run(){
                flag[1] = true;
                for(int i=0; i<10000; i++)
                    decrease();
            }
        });
        t1.start();
        t2.start();

        try{
            t1.join();
            t2.join();
        }catch(Exception e){
            System.out.println(e.getMessage());
        }
        System.out.println("Value: " + counter);
    }
}