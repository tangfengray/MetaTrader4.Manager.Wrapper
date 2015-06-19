namespace P23.MetaTrader4.Manager.Contracts
{
   public class MarginLevel
   {
       public int Login { get; set; }           // user login
       public string Group { get; set; }        // user group
       public int Leverage { get; set; }        // user leverage
       public int Updated { get; set; }         // (internal)
       public double Balance { get; set; }      // balance+credit
       public double Equity { get; set; }       // equity
       public int Volume { get; set; }          // lots
       public double Margin { get; set; }       // margin requirements
       public double MarginFree { get; set; }   // free margin
       public double Level { get; set; }  // margin level
       public int MarginType { get; set; }      // margin controlling type (percent/currency)
       public int LevelType { get; set; }       // level type(ok/margincall/stopout)
   }
}
