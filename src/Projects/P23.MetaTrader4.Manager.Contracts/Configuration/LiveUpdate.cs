using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    public class LiveUpdate
    {
        public string Company { get; set; }                  // company
        public string Path { get; set; }                     // path to LiveUpdate
        public int Version { get; set; }                     // version
        public int Build { get; set; }                       // build
        public int MaxConnect { get; set; }                  // max. simultaneous connections
        public int Connections { get; set; }                 // current connections (read only)
        public int Type { get; set; }                        // type LIVE_UPDATE_*
        public int Enable { get; set; }                      // enable
        public int TotalFiles { get; set; }                  // total files count
        public IList<LiveInfoFile> Files { get; set; }       // files' configurations
    }

    public class LiveInfoFile
    {
        public string File { get; set; }                     // file name
        public int Size { get; set; }                        // file size
        public string Hash { get; set; }                     // file hash
    }
}
