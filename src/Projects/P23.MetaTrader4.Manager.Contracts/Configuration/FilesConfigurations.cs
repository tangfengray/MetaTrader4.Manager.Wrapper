namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents files configuration
    /// </summary>
    public class FilesConfigurations
    {
        /// <summary>
        /// File name
        /// </summary>
        public string File { get; set; }

        /// <summary>
        /// File size
        /// </summary>
        public int Size { get; set; }

        /// <summary>
        /// File hash
        /// </summary>
        public string Hash { get; set; }
    }
}