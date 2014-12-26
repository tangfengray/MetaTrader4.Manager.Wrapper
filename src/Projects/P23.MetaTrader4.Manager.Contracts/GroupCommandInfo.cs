using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class GroupCommandInfo
    {
        public int Len { get; set; }             // length of users list
        public char Command { get; set; }        // group coommand
        public string NewGroup { get; set; }     // new group
        public int Leverage { get; set; }        // new leverage
    }
}
