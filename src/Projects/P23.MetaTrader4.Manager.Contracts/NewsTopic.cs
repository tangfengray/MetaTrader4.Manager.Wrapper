using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class NewsTopic
    {
        public UInt32 Key { get; set; }               // news key
        public UInt32 Time { get; set; }              // news time
        public string Ctm { get; set; }               // news source time ("yyyy/mm/dd hh:mm:ss")
        public string Topic { get; set; }             // news topic
        public string Category { get; set; }          // news category
        public string Keywords { get; set; }          // news keywords
        public string Body { get; set; }              // body (if present)
        public int BodyLen { get; set; }              // body length
        public int Readed { get; set; }               // readed flag
        public int Priority { get; set; }             // news priority: 0-general, 1-high
        public int Langid { get; set; }               // news LANGID
    }
}
