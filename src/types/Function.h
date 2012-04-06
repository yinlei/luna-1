#ifndef FUNCTION_H
#define FUNCTION_H

#include "Value.h"
#include "../Instruction.h"
#include "../NameSet.h"

namespace lua
{
    class Function : public Value, public InstructionSet
    {
    public:
        explicit Function(std::unique_ptr<UpvalueNameSet> &&upvalue_set);

        virtual int Type() const
        {
            return TYPE_FUNCTION;
        }

        virtual std::string Name() const
        {
            return "function";
        }

        virtual std::size_t GetHash() const;
        virtual bool IsEqual(const Value *other) const;

        bool HasUpvalue() const;
        const UpvalueNameSet * GetUpvalueSet() const;

    private:
        std::unique_ptr<UpvalueNameSet> upvalue_set_;
    };
} // namespace lua

#endif // FUNCTION_H
