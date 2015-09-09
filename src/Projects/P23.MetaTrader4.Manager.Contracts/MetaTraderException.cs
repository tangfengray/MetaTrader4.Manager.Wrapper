using System;
using System.Runtime.Serialization;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Exception which thrown whenever problems occurs during API call
    /// </summary>
    [Serializable]
    public class MetaTraderException : Exception
    {
        /// <summary>
        /// Error code returned by API
        /// </summary>
        public int ErrorCode { get; set; }

        /// <summary>
        /// Ctor to istantiante exception
        /// </summary>
        public MetaTraderException() { }

        /// <summary>
        /// Ctor to istantiante exception
        /// </summary>
        public MetaTraderException(string message) : base(message) { }

        /// <summary>
        /// Ctor to istantiante exception
        /// </summary>
        public MetaTraderException(string message, Exception inner) : base(message, inner) { }

        /// <summary>
        /// Ctor to istantiante exception
        /// </summary>
        protected MetaTraderException(
          SerializationInfo info,
          StreamingContext context)
            : base(info, context) { }
    }
}
