using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace P23.MetaTrader4.Manager.Contracts.Configuration
{
    public class Group
    {
        //--- common settings
        public string Name{get;set;}                   // group name
        public int Enable{get;set;}                     // enable group
        public int Timeout{get;set;}                    // trade confirmation timeout (seconds)
        public int AdvSecurity{get;set;}                // enable advanced security
        //--- statements
        public string Company{get;set;}                 // company name
        public string Signature{get;set;}               // statements signature
        public string SupportPage{get;set;}             // company support page
        public string SmtpServer{get;set;}              // statements SMTP server
        public string SmtpLogin{get;set;}               // statements SMTP login
        public string SmtpPassword{get;set;}            // statements SMTP password
        public string SupportEmail{get;set;}            // support email
        public string Templates{get;set;}               // path to directory with custom templates
        public int Copies{get;set;}                     // copy statements on support email
        public int Reports{get;set;}                    // enable statements
        //--- default settings
        public int DefaultLeverage{get;set;}            // default leverage (user don't specify leverage himself)
        public double DefaultDeposit{get;set;}          // default deposit  (user don't specify balance  himself)
        //--- securities
        public int MaxSecurities{get;set;}              // maximum simultaneous securities
        public IList<GroupSecurity> SecGroups{get;set;} // security group settings
        public IList<GroupMargin> SecMargins{get;set;}  // special securities settings
        public int SecMarginsTotal{get;set;}            // count of special securities settings
        //--- margin & interest
        public string Currency{get;set;}                // deposit currency
        public double Credit{get;set;}                  // virtual credit
        public int MarginCall{get;set;}                 // margin call level (percents)
        public int MarginMode{get;set;}                 // margin mode-MARGIN_DONT_USE,MARGIN_USE_ALL,MARGIN_USE_PROFIT,MARGIN_USE_LOSS
        public int MarginStopout{get;set;}              // stop out level
        public double InterestRate{get;set;}            // annual interest rate (percents)
        public int UseSwap{get;set;}                    // use rollovers & interestrate
        //--- rights
        public int News{get;set;}                       // news mode
        public int Rights{get;set;}                     // rights bit mask-ALLOW_FLAG_EMAIL
        public int CheckIePrices{get;set;}              // check IE prices on requests
        public int MaxPositions{get;set;}               // maximum orders and open positions
        public int CloseReopen{get;set;}                // partial close mode (if !=0 original position will be fully closed and remain position will be fully reopened)
        public int HedgeProhibited{get;set;}            // hedge prohibition flag
        public int CloseFifo{get;set;}                  // fifo rule 
        public int HedgeLargeLeg{get;set;}              // use large leg margin for hedged positions        
        //---
        public int MarginType{get;set;}                 // margin controlling type { MARGIN_TYPE_PERCENT,  MARGIN_TYPE_CURRENCY }
        //--- archives
        public int ArchivePeriod{get;set;}              // inactivity period after which account moves to archive base (in days)
        public int ArchiveMaxBalance{get;set;}          // maxumum balance of accounts to move in archive base
        //---
        public int StopOutSkipHedged{get;set;}          // skip fully hedged accounts when checking for stopout
        public int ArchivePendingPeriod{get;set;}       // pendings clean period
        //--- allowed news languages
        public IList<UInt32> NewsLanguages{get;set;}    // LANGID array
        public UInt32 NewsLanguagesTotal{get;set;}      // news languages total
    }
}
