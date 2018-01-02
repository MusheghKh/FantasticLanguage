//
// Created by max on 1/2/18.
//

#ifndef OWNCPP_ASTSTATEMENT_H
#define OWNCPP_ASTSTATEMENT_H

#include <string>
#include <vector>
#include <stdexcept>
#include <iostream>

#include "AstExpression.h"
#include "../utils/common_utils.h"

using namespace std;
//using namespace storage;
using namespace utils;

namespace ast{

    class Statement {
    public:
        virtual ~Statement() = 0;

        virtual void execute() const = 0;

        virtual string toString() const = 0;

    };

    class PrintStatement : public Statement{
    public:
        explicit PrintStatement(const Expression *exprIn);

        ~PrintStatement() override;

        void execute() const override;

        string toString() const override;

    private:
        const Expression* expr;
    };

    class AssignmentStatement : public Statement{
    public:

        AssignmentStatement(string variableIn, const Expression* exprIn);

        ~AssignmentStatement() override;

        void execute() const override;

        string toString() const override;

    private:

        const string variable;
        const Expression* expr;
    };

    class IfStatement : public Statement{
    public:
        IfStatement(const Expression *exprIn, const Statement *ifStatementIn, const Statement *elseStatementIn);

        IfStatement(const Expression *exprIn, const Statement *ifStatementIn);

        ~IfStatement() override;

        void execute() const override;

        string toString() const override;

    private:

        const Expression *expr;
        const Statement *ifStatement, *elseStatement = nullptr;
    };

    class BlockStatement : public Statement{
    public:
        BlockStatement() = default;

        ~BlockStatement() override;

        void add(const Statement* statement);

        void execute() const override;

        string toString() const override;

    private:

        vector<const Statement*> statements{};
    };

    class WhileStatement : public Statement{
    public:
        WhileStatement(const Expression *conditionIn, const Statement *bodyIn);

        ~WhileStatement() override;

        void execute() const override;

        string toString() const override;

    private:

        const Expression *condition;
        const Statement *body;
    };

    class DoWhileStatement : public Statement{
    public:
        DoWhileStatement(const Expression *condition, const Statement *body);

        ~DoWhileStatement() override;

        void execute() const override;

        string toString() const override;

    private:
        const Expression *condition;
        const Statement *body;
    };

    class ForStatement : public Statement{
    public:
        ForStatement(const Statement *initializationIn, const Expression *terminationIn, const Statement *incrementIn,
                     const Statement *bodyIn);

        ~ForStatement() override;

        void execute() const override;

        string toString() const override;

    private:
        const Statement *initialization;
        const Expression *termination;
        const Statement *increment;
        const Statement *body;
    };

    class BreakStatement : public runtime_error, public Statement{
    public:
        explicit BreakStatement();

        ~BreakStatement() override = default;

        void execute() const override;

        string toString() const override;

    };

    class ContinueStatement : public runtime_error, public Statement{
    public:

        explicit ContinueStatement();

        ~ContinueStatement() override = default;

        void execute() const override;

        string toString() const override;
    };
}

#endif //OWNCPP_ASTSTATEMENT_H
