using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    public class Holiday
    {
        public int Year { get; set; }                    // year
        public int Month { get; set; }                   // month
        public int Day { get; set; }                     // day
        public int From { get; set; }                    // work time-from (minutes)
        public int To { get; set; }                      // work time-to (minutes)
        public string Symbol { get; set; }               // security name or symbol's group name or "All"
        public string Description { get; set; }          // description
        public int Enable { get; set; }                  // enable
    }
}
