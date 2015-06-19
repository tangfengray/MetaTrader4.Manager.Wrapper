using System;
using System.Collections.Generic;

namespace P23.MetaTrader4.Manager.Contracts
{
    public class RequestInfo
    {
        //--- general props
        public int Id{get;set;}                  // request id
        public char Status{get;set;}             // request status
        public UInt32 Time{get;set;}             // request time
        public int Manager{get;set;}             // manager processing request (if any)
        //--- user info
        public int Login{get;set;}               // user login
        public string Group{get;set;}            // user group
        public double Balance{get;set;}          // user balance
        public double Credit{get;set;}           // user credit
        //--- processing trade transaction
        public IList<double> Prices{get;set;}    // bid/ask
        public TradeTransInfo Trade{get;set;}    // trade transaction
        public int GwVolume{get;set;}            // gateway order volume
        public int GwOrder{get;set;}             // gateway order ticket
        public short GwPrice{get;set;}           // gateway order price deviation (pips) from request price
    }
}
