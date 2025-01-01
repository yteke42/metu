const db = require("../routes/db-config");
const bcrypt = require("bcryptjs");


const newpass = async (req, res) => {
    const {email, randomNumber2, newpassword: Nnewpassword} = req.body;
    db.query("SELECT * FROM users WHERE email = ?", [email], async (Err, result) => {
        if (Err) throw Err;

        if (result[0]["randomNumber"] != randomNumber2) return res.json({status:"error", error:"Wrong recovery number"})
        else {
            const newpassword = await bcrypt.hash(Nnewpassword, 8);
            res.json({status:"success", success:"Password has successfully been changed"})
            var newp = "UPDATE users SET password = '"+ newpassword + "' WHERE randomNumber = '" + result[0]["randomNumber"] + "'";
            db.query(newp, (error, result) => {
                if (error) throw error;
            })
        }
}
)}
module.exports = newpass;