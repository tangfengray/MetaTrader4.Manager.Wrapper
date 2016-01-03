using P23.MetaTrader4.Manager.Contracts.Configuration.Enums;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents margin level
    /// </summary>
    public class MarginLevel
    {
        /// <summary>
        /// User login
        /// </summary>
        public int Login { get; set; }

        /// <summary>
        /// User group
        /// </summary>
        public string Group { get; set; }

        /// <summary>
        /// User leverage
        /// </summary>
        public int Leverage { get; set; }

        /// <summary>
        /// (internal)
        /// </summary>
        public int Updated { get; set; }

        /// <summary>
        /// Balance + Credit
        /// </summary>
        public double Balance { get; set; }

        /// <summary>
        /// Equity
        /// </summary>
        public double Equity { get; set; }

        /// <summary>
        /// Lots
        /// </summary>
        public int Volume { get; set; }

        /// <summary>
        /// Margin requirements
        /// </summary>
        public double Margin { get; set; }

        /// <summary>
        /// Free margin
        /// </summary>
        public double MarginFree { get; set; }

        /// <summary>
        /// Margin level
        /// </summary>
        public double Level { get; set; }

        /// <summary>
        /// Margin controlling type (percent/currency)
        /// </summary>
        public MarginControllingType MarginType { get; set; }

        /// <summary>
        /// Level type(ok/margincall/stopout)
        /// </summary>
        public MarginLevelType LevelType { get; set; }
    }
}
