namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents group command
    /// </summary>
    public class GroupCommandInfo
    {
        /// <summary>
        /// Length of users list
        /// </summary>
        public int Len { get; set; }

        /// <summary>
        /// Group coommand
        /// </summary>
        public char Command { get; set; }

        /// <summary>
        /// New group
        /// </summary>
        public string NewGroup { get; set; }

        /// <summary>
        /// New leverage
        /// </summary>
        public int Leverage { get; set; }
    }
}
