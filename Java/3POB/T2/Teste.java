class Teste {
   public static void main(String[] args) {

      Unica u = Unica.pegaInstancia();

      Unica v = Unica.pegaInstancia();

      Unica x = Unica.pegaInstancia();

      System.out.println((u == v) && (x == v)); // Deve retornar true

   }

   public class Unica extends Teste
   {
      private static Unica instancia;

      private Unica(){}

      public static Unica pegaInstancia()
      {
         if(instancia == null)
         {
            instancia = Unica();
         }
         return instancia;
      }
   }

   //A Classe tem que ser Static para a instância ser única, sempre que tentar ser criada vai ser a mesma instância , mas não faço a menor idéia de como cria um teste pra conseguir ler e testar
 
}