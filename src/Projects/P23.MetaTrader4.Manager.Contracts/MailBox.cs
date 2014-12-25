using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class MailBox
    {
        public UInt32 Time { get; set; }              // receive time
        public int Sender { get; set; }               // mail sender (login)
        public string From { get; set; }              // mail sender (name)
        public int To { get; set; }                   // mail recipient
        public string Subject { get; set; }           // mail sumbect
        public int Readed { get; set; }               // readed flag
        public string Body { get; set; }              // pointer to mail body
        public int BodyLen { get; set; }              // mail body length
        public short BuildMin { get; set; }           // minimum build
        public short BuildMax { get; set; }           // maximum build
    }
}
