#ifndef BDN_IOS_UiProvider_HH_
#define BDN_IOS_UiProvider_HH_

#include <bdn/IUiProvider.h>

namespace bdn
{
namespace ios
{

class UiProvider : public Base, BDN_IMPLEMENTS IUiProvider
{
public:
    UiProvider();
    

    
    String getName() const override;
    
    P<IViewCore> createViewCore(const String& coreTypeName, View* pView) override;


    static UiProvider& get();
    
    
    double				uiLengthToDips(const UiLength& uiLength) const
    {
        if(uiLength.unit==UiLength::sem)
            return (int)std::lround( uiLength.value * _semDips );
        
        else if(uiLength.unit==UiLength::dip)
            return uiLength.value;
        
        else
            throw InvalidArgumentError("Invalid UiLength unit passed to UiProvider::uiLengthToDips: "+std::to_string((int)uiLength.unit) );
    }
    
    Margin			uiMarginToDipMargin(const UiMargin& margin) const
    {
        return Margin(
                      uiLengthToDips(margin.top),
                      uiLengthToDips(margin.right),
                      uiLengthToDips(margin.bottom),
                      uiLengthToDips(margin.left) );
    }

private:
    double _semDips;
};

}
}


#endif
