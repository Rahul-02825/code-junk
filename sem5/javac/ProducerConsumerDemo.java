class Stock{
    private int items=0;
    private int capacity=10;
    
    public synchronized  void addStock(){
        while(items>=capacity){
            try {
                System.out.println("waiting for producer to add");
                wait();
                
            } catch (Exception e) {
                e.getMessage();
            }
        }
        System.out.println("adding stock");
        items++;
        notify();
    }
    
    public synchronized void getstock(){
        while(items==0){
            try{
                System.out.println("consumer waiting to take");
                wait();
            }
            catch(Exception e){
                e.getMessage();
            }
        }
        System.out.println("removing stock");
        items--;
        notify();
    }
}
class Producer  implements Runnable{
    private Stock stock;

    Producer(Stock stock){
        this.stock=stock;
    }
    @Override
    public void run(){
       for(int i=0;i<20;i++){

        stock.addStock();
       }
        
    }

}
class Consumer implements Runnable{
    private Stock stock;

    Consumer(Stock stock){
        this.stock=stock;
    }
    @Override
    public void run(){
       for(int i=0;i<20;i++){
        stock.getstock();
       }
        
    }

}
class ProducerConsumerDemo{
    public static void main(String[] args) {
        Stock stock=new Stock();
        Producer producer=new Producer(stock);
        Consumer consumer=new Consumer(stock);
        Thread thread_prod=new Thread(producer);
        Thread thread_cons=new Thread(consumer);

        thread_cons.start();
        thread_prod.start();

        try{
            thread_prod.join();
            thread_cons.join();
        }
        catch(Exception e){
            System.out.println("error occured");

        }
        System.out.println("finished");
    }
}