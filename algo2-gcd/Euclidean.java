class Main{
    public static void main (String [] args){
        new Main();
    }

    public Main(){
        System.out.println(gcd(8, 7));
        System.out.println(gcd(8, 4));
        System.out.println(gcd(4, 2));
    }
    
    // Requires: a > b
    public int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
}