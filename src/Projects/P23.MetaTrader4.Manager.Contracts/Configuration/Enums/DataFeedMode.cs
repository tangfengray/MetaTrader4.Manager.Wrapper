namespace P23.MetaTrader4.Manager.Contracts.Configuration.Enums
{
    public enum DataFeedMode
    {
        Quotes = 0,
        News = 1,
        QuotesNews = 2
    }

    public enum SynchronizationMode
    {
        Add,
        Update,
        Insert,
        Delete,
        Last
    }

    public enum EnGatewayAccountFlags
    {
        None = 0,
        Quotes = 1
    }
}