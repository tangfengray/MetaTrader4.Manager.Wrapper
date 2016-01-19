using System;
using System.Collections.Generic;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class NewsTopicNew
    {
        /// <summary>
        /// News key
        /// </summary>
        public UInt32 Key{ get; set; }

        /// <summary>
        /// News language (WinAPI LANGID)
        /// </summary>
        public UInt32 Language{ get; set; }

        /// <summary>
        /// News subject
        /// </summary>
        public string Subject{ get; set; }

        /// <summary>
        /// News category
        /// </summary>
        public string Category{ get; set; }

        /// <summary>
        /// EnNewsFlags
        /// </summary>
        public EnNewsFlags Flags{ get; set; }

        /// <summary>
        /// News body
        /// </summary>
        public string Body{ get; set; }

        /// <summary>
        /// List of languages available for news
        /// </summary>
        public List<UInt32> LanguagesList{ get; set; }

        /// <summary>
        /// News time
        /// </summary>
        public Int64 DateTime{ get; set; }
    }
}