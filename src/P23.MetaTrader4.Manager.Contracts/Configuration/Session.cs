namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    /// <summary>
    /// Object that represents session configuration
    /// </summary>
    public class Session
    {
        /// <summary>
        /// Session open  time: hour
        /// </summary>
        public short OpenHour { get; set; }

        /// <summary>
        /// Session open  time: minute
        /// </summary>
        public short OpenMin { get; set; }

        /// <summary>
        /// Session close time: hour
        /// </summary>
        public short CloseHour { get; set; }

        /// <summary>
        /// Session close time: minute
        /// </summary>
        public short CloseMin { get; set; }
    }
}