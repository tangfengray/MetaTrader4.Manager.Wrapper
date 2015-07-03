namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    public class GatewayMarkup
    {
        public int Enable { get; set; }                     // enable flag 0 - disabled, 1 - enabled
        public string Source { get; set; }                  // source symbol\symbols mask\symbols group name
        public string Symbol { get; set; }                  // local symbol name
        public string AccountName { get; set; }             // account name (obsolete)
        public int AccountID { get; set; }                  // account internal id (obsolete)
        public int BidMarkup { get; set; }                  // bid markup in pips
        public int AskMarkup { get; set; }                  // ask markup in pips
    }
}