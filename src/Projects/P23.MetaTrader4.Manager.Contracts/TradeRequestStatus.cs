namespace P23.MetaTrader4.Manager.Contracts
{
    public enum TradeRequestStatus : sbyte
    {
        Empty,
        Request,
        Locked,
        Answered,
        Reseted,
        Canceled
    }
}