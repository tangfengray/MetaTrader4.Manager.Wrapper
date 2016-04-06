namespace P23.MetaTrader4.Manager.Contracts.Configuration.Enums
{
    /// <summary>
    /// One-Time password mode
    /// </summary>
    public enum OTPMode
    {
        /// <summary>
        /// Disabled
        /// </summary>
        Disabled = 0,

        /// <summary>
        /// Sha256 mode
        /// </summary>
        TotpSha256 = 1,
    }
}