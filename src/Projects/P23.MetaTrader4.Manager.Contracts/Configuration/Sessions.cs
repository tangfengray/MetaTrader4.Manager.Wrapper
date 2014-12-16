using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    public class Sessions
    {
        public IList<Session> Quote { get; set; }  // quote sessions
        public IList<Session> Trade { get; set; }  // trade sessions
    }

    public class Session
    {
        public short OpenHour { get; set; }        // session open  time: hour & minute
        public short OpenMin { get; set; }
        public short CloseHour { get; set; }       // session close time: hour & minute
        public short CloseMin { get; set; }
    }
}
