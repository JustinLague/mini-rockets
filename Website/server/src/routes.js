// Import Controllers
const AppController = require("./controllers/app.controller");


module.exports = (app) => {
    //app
    app.get("/api/hello", AppController.hello);
};
