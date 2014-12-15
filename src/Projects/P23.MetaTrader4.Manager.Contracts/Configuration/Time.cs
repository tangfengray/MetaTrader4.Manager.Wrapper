using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    public class Time
    {
        public IList<IList<int>> Days { get; set; }   // server's accessebility (7 days-24 hours, 0-denied, 1-allowed)
    }
}
