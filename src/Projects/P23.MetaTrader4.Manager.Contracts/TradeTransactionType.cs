namespace P23.MetaTrader4.Manager.Contracts
{
    public enum TradeTransactionType : byte
    {
        PricesGet,                      // prices requets
        PricesRequote,                  // requote
        //--- client trade transaction
        OrderIeOpen = 64,                // open order (Instant Execution)
        OrderReqOpen,                  // open order (Request Execution)
        OrderMkOpen,                   // open order (Market Execution)
        OrderPendingOpen,              // open pending order
        //---
        OrderIeClose,                  // close order (Instant Execution)
        OrderReqClose,                 // close order (Request Execution)
        OrderMkClose,                  // close order (Market Execution)
        //---
        OrderModify,                    // modify pending order
        OrderDelete,                    // delete pending order
        OrderCloseBy,                  // close order by order
        OrderCloseAll,                 // close all orders by symbol
        //--- broker trade transactions
        BrOrderOpen,                   // open order
        BrOrderClose,                  // close order
        BrOrderDelete,                 // delete order (ANY OPEN ORDER!!!)
        BrOrderCloseBy,               // close order by order
        BrOrderCloseAll,              // close all orders by symbol
        BrOrderModify,                 // modify open price, stoploss, takeprofit etc. of order
        BrOrderActivate,               // activate pending order
        BrOrderComment,                // modify comment of order
        BrBalance                       // balance/credit
    }
}