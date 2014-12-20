using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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
          System.Runtime.Serialization.SerializationInfo info,
          System.Runtime.Serialization.StreamingContext context)
            : base(info, context) { }
    }
}
