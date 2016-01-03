using System;

namespace P23.MetaTrader4.Manager.Contracts
{
    /// <summary>
    /// Object that represents news topic
    /// </summary>
    public class NewsTopic
    {
        /// <summary>
        /// News key
        /// </summary>
        public UInt32 Key { get; set; }

        /// <summary>
        /// News time
        /// </summary>
        public UInt32 Time { get; set; }

        /// <summary>
        /// News source time ("yyyy/mm/dd hh:mm:ss")
        /// </summary>
        public string Ctm { get; set; }

        /// <summary>
        /// News topic
        /// </summary>
        public string Topic { get; set; }

        /// <summary>
        /// News category
        /// </summary>
        public string Category { get; set; }

        /// <summary>
        /// News keywords
        /// </summary>
        public string Keywords { get; set; }

        /// <summary>
        /// Body (if present)
        /// </summary>
        public string Body { get; set; }

        /// <summary>
        /// Body length
        /// </summary>
        public int BodyLen { get; set; }

        /// <summary>
        /// Readed flag
        /// </summary>
        public int Readed { get; set; }

        /// <summary>
        /// News priority: 0-general, 1-high
        /// </summary>
        public int Priority { get; set; }

        /// <summary>
        /// News LANGID
        /// </summary>
        public int LangId { get; set; }
    }
}
