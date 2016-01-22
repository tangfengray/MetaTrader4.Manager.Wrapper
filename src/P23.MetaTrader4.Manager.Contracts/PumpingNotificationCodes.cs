namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Pumping notification codes send in Pumping Mode
    /// </summary>
    public enum PumpingNotificationCodes
    {
        /// <summary>
        /// Pumping started
        /// </summary>
        Start = 0,
        /// <summary>
        /// Update symbols
        /// </summary>
        Symbols,
        /// <summary>
        /// Update groups
        /// </summary>
        Groups,
        /// <summary>
        /// Update users
        /// </summary>
        Users,
        /// <summary>
        /// Update online users
        /// </summary>
        Online,
        /// <summary>
        /// Update bid/ask
        /// </summary>
        BidAsk,
        /// <summary>
        /// Update news
        /// </summary>
        News,
        /// <summary>
        /// Update news body
        /// </summary>
        NewsBody,
        /// <summary>
        /// Update mails
        /// </summary>
        Mail,
        /// <summary>
        /// Update trades
        /// </summary>
        Trades,
        /// <summary>
        /// Update trade requests
        /// </summary>
        Requests,
        /// <summary>
        /// Update server plugins
        /// </summary>
        Plugins,
        /// <summary>
        /// New order for activation (sl/sp/stopout)
        /// </summary>
        Activation,
        /// <summary>
        /// New margin calls
        /// </summary>
        Margincall,
        /// <summary>
        /// Pumping stopped
        /// </summary>
        Stop,
        /// <summary>
        /// Ping
        /// </summary>
        Ping,
        /// <summary>
        /// Update news in new format (NewsTopicNew structure)
        /// </summary>
        NewsNew
    }
}