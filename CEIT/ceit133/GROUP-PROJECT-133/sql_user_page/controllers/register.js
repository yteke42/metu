const db = require("../routes/db-config");
const bcrypt = require("bcryptjs");



const register = async (req, res) => {

    const {fullname, email, password: Npassword, passwordAgain: NpasswordAgain, birthdate} = req.body
    if (Npassword != NpasswordAgain) {
        return res.json({status:"error", error:"Passwords do not match."});
    }

    if (!email || !Npassword) {
        return res.json({status:"error", error:"Please enter your email and password"});
    } else {
        console.log(email);
        db.query("SELECT email FROM users WHERE email = ?", [email], async (err, result) => {
            if (err) throw err;
            console.log(result[0])
            if (result[0]) {
                return res.json({status:"error", error:"Email has already been registered"})
            } else {
                const password = await bcrypt.hash(Npassword, 8);
                var randomNumber = Math.floor((Math.random() * 10000) + 1000)
                db.query("INSERT INTO users SET ?", {fullname: fullname, email: email, password: password, randomNumber: randomNumber}, (error, results) => {
                    if (error) throw error;
                    return res.json({ status: "success", success: "User has been registered", ranNum: "Save This Number for Future Password Recovery!\n" + randomNumber  })
                })
            }
        })
    }
}
module.exports = register;