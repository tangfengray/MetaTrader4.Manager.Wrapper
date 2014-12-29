using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class ExposureValue
    {
        public string Currency { get; set; }         // currency
        public double Clients { get; set; }          // clients volume
        public double Coverage { get; set; }         // coverage volume
    }
}
