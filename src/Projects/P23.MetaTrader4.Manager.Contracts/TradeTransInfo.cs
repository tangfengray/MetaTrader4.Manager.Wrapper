using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class TradeTransInfo
    {
        public byte Type { get; set; }          // trade transaction type
        public short Cmd { get; set; }          // trade command
        public int Order { get; set; }          // order
        public int OrderBy { get; set; }        // order by
        public string Symbol { get; set; }      // trade symbol
        public int Volume { get; set; }         // trade volume
        public double Price { get; set; }       // trade price
        public double Sl { get; set; }          // stoploss
        public double Tp { get; set; }          // takeprofit
        public int IeDeviation { get; set; }    // deviation on IE
        public string Comment { get; set; }     // comment
        public UInt32 Expiration { get; set; }  // pending order expiration time
        public int Crc { get; set; }            // crc
    }
}
