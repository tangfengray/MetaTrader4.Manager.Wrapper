namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents server log
    /// </summary>
    public class ServerLog
    {
        /// <summary>
        /// Code
        /// </summary>
        public int Code { get; set; }

        /// <summary>
        /// Time
        /// </summary>
        public string Time { get; set; }

        /// <summary>
        /// IP
        /// </summary>
        public string Ip { get; set; }

        /// <summary>
        /// Message
        /// </summary>
        public string Message { get; set; }
    }
}