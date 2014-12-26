using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class ReportGroupRequest
    {
        public string Name { get; set; }            // request group name
        public UInt32 From { get; set; }            // from
        public UInt32 To { get; set; }              // to
        public int Total { get; set; }              // total logins in request group
    }
}
