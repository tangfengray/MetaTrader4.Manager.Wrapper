namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Group operation command type
    /// </summary>
    public enum GroupCommands : sbyte
    {
        /// <summary>
        /// Delete users
        /// </summary>
        Delete,
        /// <summary>
        /// Enable users
        /// </summary>
        Enable,
        /// <summary>
        /// Disable users
        /// </summary>
        Disable,
        /// <summary>
        /// Change leverage
        /// </summary>
        Leverage,
        /// <summary>
        /// Set group
        /// </summary>
        SetGroup
    }
}