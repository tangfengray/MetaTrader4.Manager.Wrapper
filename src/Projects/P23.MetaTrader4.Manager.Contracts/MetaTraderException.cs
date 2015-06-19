using System;
using System.Runtime.Serialization;

namespace P23.MetaTrader4.Manager.Contracts
{
    [Serializable]
    public class MetaTraderException : Exception
    {
        public int ErrorCode { get; set; }
        public MetaTraderException() { }
        public MetaTraderException(string message) : base(message) { }
        public MetaTraderException(string message, Exception inner) : base(message, inner) { }
        protected MetaTraderException(
          SerializationInfo info,
          StreamingContext context)
            : base(info, context) { }
    }
}
