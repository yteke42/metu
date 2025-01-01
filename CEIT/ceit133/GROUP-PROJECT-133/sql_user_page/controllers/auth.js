const express = require("express");
const register = require("./register");
const login = require("./login");
const newpass = require("./newpass")
const router = express.Router();


router.post("/register", register)
router.post("/login", login)
router.post("/newpass", newpass)

module.exports = router;