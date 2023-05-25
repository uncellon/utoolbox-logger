#ifndef UT_ABSTRACT_MESSAGE_LAYOUT_H
#define UT_ABSTRACT_MESSAGE_LAYOUT_H

#include <any>
#include <string>

namespace UT {

class AbstractMessageLayout {
public:
    /**************************************************************************
     * Methods
     *************************************************************************/

    virtual std::string build(const std::any values[]) = 0;

}; // class AbstractMessageLayout

} // namespace UT

#endif // UT_ABSTRACT_MESSAGE_LAYOUT_H