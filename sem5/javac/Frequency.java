import java.util.*;

class Computes implements Runnable{
    private String s;

    Computes(String s){
        this.s=s;
    }
    public void run(){
        HashMap<Character,Integer> hasher=new HashMap<>();
        for(int i=0;i< s.length();i++){
            char currentchar=s.charAt(i);
            if(hasher.containsKey(currentchar)){
                int x=hasher.get(currentchar);
                hasher.put(currentchar,x+1);
            }
            else{ 
                hasher.put(currentchar,1);
            }
        }
        for(Character key:hasher.keySet()){
            System.out.println(key+":"+hasher.get(key));
        }

    }
    
}

class Frequency {
    public static void main(String[] args) {
        Computes[] arr_comp=new Computes[6];
        Thread [] threads=new Thread[6];

        int i;
        for(i=0;i<1;i++){
            arr_comp[i]=new Computes("raahulllllllfdsfsdfdfwerrwereeeerreftjukuuuuyutyutyuyhrevtdtdyfyjbukndsdftrygujnkbtvryc");
            threads[i]=new Thread(arr_comp[i]);
            threads[i].start();
        }

        for(Thread th:threads){
            try {
                th.join();

            } catch (Exception e) {
                e.getMessage();
            }
        }

    }
}
