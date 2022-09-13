class AppController {
    async hello(req, res) {
        try {
            res.send("Hello world");
        } catch (err) {
            res.status(400).send({ error: err.message });
        }
    }
}

module.exports = new AppController();