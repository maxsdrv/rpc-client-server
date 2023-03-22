/*
The Command Pattern is a good choice if you want to decouple the client and server logic and make it easy to add new statements in the future. It can also be useful if you want to implement undo/redo functionality in your application.

However, it might not necessarily be more efficient than other patterns like the Proxy Pattern or Observer Pattern in terms of performance. The efficiency of a pattern depends on the specific requirements of your project and the trade-offs you are willing to make.

That being said, the Command Pattern can be a good choice for your project since it provides a clear separation of concerns and allows you to easily add new statements without modifying existing code.
*/


/*
In this example, the Command interface defines a method execute that can be implemented by different command classes. The AlgorithmCommand class encapsulates an algorithm object and implements the execute method.

The StatementExecutor class maintains a list of commands and can execute them when required. The Client can create a Command object and add it to the StatementExecutor. The Server can then execute all the commands by invoking the executeCommands method on the StatementExecutor.

Note that this is just a basic example to give you an idea of how you could use the Command Pattern in your project. You will need to adapt it to your specific requirements and use the appropriate gRPC or Qt APIs to implement the communication between the client and server.

*/

class Command {
public:
    virtual void execute() = 0;
};

class AlgorithmCommand : public Command {
public:
    AlgorithmCommand(Algorithm* algorithm) : algorithm_(algorithm) {}

    void execute() override {
        algorithm_->execute();
    }

private:
    Algorithm* algorithm_;
};

class StatementExecutor {
public:
    void addCommand(Command* command) {
        commands_.push_back(command);
    }

    void executeCommands() {
        for (auto& command : commands_) {
            command->execute();
        }
    }

private:
    std::vector<Command*> commands_;
};

class Client {
public:
    void executeStatement(const std::string& statement) {
        Algorithm* algorithm = AlgorithmFactory::createAlgorithm(statement);
        Command* command = new AlgorithmCommand(algorithm);
        statementExecutor_->addCommand(command);
    }

private:
    StatementExecutor* statementExecutor_;
};

class Server {
public:
    void executeStatements() {
        statementExecutor_->executeCommands();
    }

private:
    StatementExecutor* statementExecutor_;
};





/*
  example of how you could integrate gRPC and Qt signals and slots into the previous 			implementation using the Command Pattern:
*/

/*
In this example, we've added a Client class that uses a gRPC stub to call the ExecuteStatement method on the server. The Client also emits a statementExecuted signal whenever a statement is executed, which can be connected to a slot to display the results on the UI.

The Server class now emits a statementExecuted signal whenever a statement is executed, which can be connected to a slot to update the UI or perform other tasks.

We've also added a gRPC service implementation AlgorithmServiceImpl that uses the Server's executeStatement method to execute the statement and sends the result back to the client using the gRPC writer.
*/

// Command interface remains the same as before

class AlgorithmCommand : public Command {
public:
    AlgorithmCommand(Algorithm* algorithm) : algorithm_(algorithm) {}

    void execute() override {
        algorithm_->execute();
    }

private:
    Algorithm* algorithm_;
};

// StatementExecutor class remains the same as before

class Client {
public:
    Client(std::shared_ptr<grpc::Channel> channel) : stub_(AlgorithmService::NewStub(channel)) {
        QObject::connect(this, &Client::statementExecuted, this, &Client::onStatementExecuted);
    }

    void executeStatement(const std::string& statement) {
        Algorithm* algorithm = AlgorithmFactory::createAlgorithm(statement);
        Command* command = new AlgorithmCommand(algorithm);
        statementExecutor_->addCommand(command);
        
        // Invoke the gRPC service method to execute the statement on the server
        grpc::ClientContext context;
        Statement request;
        request.set_statement(statement);
        grpc::Status status = stub_->ExecuteStatement(&context, request, nullptr);
        if (!status.ok()) {
            qDebug() << "Failed to execute statement: " << status.error_message().c_str();
        }
    }

signals:
    void statementExecuted(const std::string& statement, const std::string& result);

private slots:
    void onStatementExecuted(const std::string& statement, const std::string& result) {
        qDebug() << "Statement executed: " << statement.c_str();
        qDebug() << "Result: " << result.c_str();
    }

private:
    std::unique_ptr<AlgorithmService::Stub> stub_;
};

class Server {
public:
    Server() {
        QObject::connect(this, &Server::statementExecuted, this, &Server::onStatementExecuted);
    }

    void executeStatements() {
        statementExecutor_->executeCommands();
    }

    void onStatementExecuted(const std::string& statement, const std::string& result) {
        emit statementExecuted(statement, result);
    }

signals:
    void statementExecuted(const std::string& statement, const std::string& result);

private:
    StatementExecutor* statementExecutor_;
};

// gRPC service implementation
class AlgorithmServiceImpl final : public AlgorithmService::Service {
public:
    AlgorithmServiceImpl(Server* server) : server_(server) {}

    grpc::Status ExecuteStatement(grpc::ServerContext* context, const Statement* request, grpc::ServerWriter<Result>* writer) override {
        // Execute the statement using the server's StatementExecutor
        server_->executeStatement(request->statement());

        // Send the result back to the client using the gRPC writer
        Result result;
        result.set_result("Statement executed successfully");
        writer->Write(result);

        return grpc::Status::OK;
    }

private:
    Server* server_;
};
























